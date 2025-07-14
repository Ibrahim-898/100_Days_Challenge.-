const express = require('express');
const app = express();
const path = require('path');
const userSchema = require('./models/user');
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
app.get('/profile',isloggedIn,async (req,res)=>{
    let user = await userSchema.findOne({email : req.user.email});
    console.log(user);
    res.render("profile",{user});
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
        let token = jwt.sign({email},"shhhhh");
        res.cookie("token",token);
         res.redirect("/profile");
     });

})
app.get('/homepage',(req,res)=>{
    res.render('homepage');
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

app.get("/logout",(req,res)=>{
    res.cookie("token","");
    res.redirect("/login");

})

function isloggedIn(req,res,next){
    if(req.cookies.token ==="") res.redirect("/login");
    else{
       let data =  jwt.verify(req.cookies.token,"shhhhh");
        req.user = data;
    }
    next();
}
app.listen(4000);