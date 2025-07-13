const express = require('express');
const app = express();
const path = require('path');
const userSchema = require('./models/user');
const bcrypt = require('bcrypt');
const json = require('jsonwebtoken');

app.set('view engine' ,'ejs');
app.use(express.json());
app.use(express.urlencoded({extended:true}));
app.use(express.static(path.join(__dirname,'public')));

app.get("/",(req,res)=>{
    res.render("register");
});

app.get('/login',(req,res)=>{
    res.render('login');
})
app.post('/login',async (req,res)=>{
    let {email,password}= req.body;
    const user = await userSchema.findOne({email});
    
    if(!user || password!==user.password ){
        return res.send("Wrong Email or Password");
    }
    console.log(user.password);
         res.redirect('homepage'); 
})
app.get('/homepage',(req,res)=>{
    res.render('homepage');
})

app.post("/create", (req,res)=>{
     let {name,email,password}=req.body;
     bcrypt.genSalt(10,  function(err, salt) {
    bcrypt.hash(password, salt, async function(err, hash) {
        const user = new userSchema({name,email,password : hash});
        await  user.save(); 
        res.redirect('login');
    });
});
   
    
    
});


app.listen(4000);