const mongoose = require('mongoose');


mongoose.connect('mongodb://127.0.0.1:27017/postsdata');

const userSchema = new mongoose.Schema({
    name : String,
    email :{
        type :String,
        required : true,
        unique : true,
    },
    password : String,
    createdAt : {
        type :Date,
        default : Date.now,
    }

});

module.exports = mongoose.model('User',userSchema);