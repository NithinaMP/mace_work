const mysql = require('mysql2');
const con = mysql.createConnection({
    host : 'localhost',
    user : 'root',
    password : 'add',
    // database: 'T_db'
});

con.connect((err)=>{
    if(err){
        console.error('Error connecting:',err.stack);
        return;

    }
    console.log('Connected to Mysql server');
    con.query('CREATE DATABASE IF NOT EXISTS T_db',(err,result)=>{
        if(err)throw err;
        con.end();
    });
});
module.exports=con;
