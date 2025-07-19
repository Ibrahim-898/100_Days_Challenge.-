const express = require('express');
const app = express();
const path = require('path');
const userSchema = require('./models/user');
const postmodel = require('./models/post');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');
const cookieParser = require('cookie-parser');

app.set('view engine' ,'ejs');
app.use(express.json());
app.use(cookieParser());
app.use(express.urlencoded({extended:true}));
app.use(express.static(path.join(__dirname,'public')));

app.get("/",(req,res)=>{
    res.render("register");
});

app.get('/login',(req,res)=>{
    res.render('login');
})
app.get('/homepage',isloggedIn,async (req,res)=>{
    let user = await userSchema.findOne({email : req.user.email});
    await user.populate("posts");
    res.render("homepage",{user});
});
app.get("/like/:id",isloggedIn,async (req,res)=>{
    let post = await postmodel.findOne({_id: req.params.id}).populate("user");
    //console.log(req.user._id);
    if(post.likes.indexOf(req.user._id)===-1){
    post.likes.push(req.user._id);
    }
    else {
        post.likes.splice(post.likes.indexOf(req.user._id),1);
    }
    
    await post.save();
    res.redirect("/homepage");
});
app.get("/edit/:id",isloggedIn, async (req,res)=>{
    let post = await postmodel.findOne({_id : req.params.id}).populate("user");
    res.render("edit",{post});
})

app.post("/update/:id",isloggedIn,async(req,res)=>{
    let post = await postmodel.findOneAndUpdate({_id: req.params.id},{content : req.body.content });
    res.redirect("/homepage");
});
app.post('/login',async (req,res)=>{
    let {email,password}= req.body;
    const user = await userSchema.findOne({email});
     if(!user ){
        return res.send("Wrong Email or Password");
    }
     bcrypt.compare(password, user.password, function(err, result) {
        if(!result){
            return res.send("Wrong Email or Password");
        }
        let token = jwt.sign({ email: user.email, id: user._id }, "shhhhh");
        res.cookie("token",token);
         res.redirect("/homepage");
     });

})

app.post("/create", async (req,res)=>{
     let {name,email,password}=req.body;
     const user = await userSchema.findOne({email});
     if(user) {
         res.status(500).send("User Already Register");
        res.redirect("/");
     }
     bcrypt.genSalt(10,  function(err, salt) {
    bcrypt.hash(password, salt, async function(err, hash) {
        let user = new userSchema({name,email,password : hash});
        await  user.save(); 
        res.redirect('/login');
    });
});
});
app.post('/post',isloggedIn,async (req,res)=>{
      let user = await userSchema.findOne({email : req.user.email});
     let {content} = req.body;
      let post = await postmodel.create({
        user: user._id,
         content,
        
      });
      user.posts.push(post._id);
      await user.save();
      res.redirect("/homepage");
});
app.get("/logout",(req,res)=>{
    res.cookie("token","");
    res.redirect("/login");

})

async function isloggedIn(req,res,next){
    if(req.cookies.token ==="") res.redirect("/login");
   let data = jwt.verify(req.cookies.token, "shhhhh");
    
    let user = await userSchema.findOne({ email: data.email });
        if (!user) return res.redirect("/login");
        req.user = user; 
        next();
;
}
app.listen(4000);