const mysql = require('mysql2');
const con = mysql.createConnection({
    host : 'localhost',
    user : 'root',
    password : 'add',
    });

con.connect((err)=>{
    if(err){
        console.error('Error connecting:',err.stack);
        return;

    }
    console.log('Connected to Mysql server');
    con.query('CREATE DATABASE IF NOT EXISTS T_db',(err,result)=>{
        if(err)throw err;
    });

module.exports=con;

const cr_Tb =`
    CREATE TABLE IF NOT EXISTS
    T_db.students(
    rollno INT PRIMARY KEY,name VARCHAR(15))`;

con.query(cr_Tb,(err)=>{
    if(err) throw err;
    console.log('Table students created');




const sql = "INSERT INTO T_db.students(rollno, name) VALUES ?";
const studentsToInsert = [
    [111, 'Priya Sharma'],
    [212, 'Mike Davis'],
    [821, 'Sarah Lee']
];

con.query(sql, [studentsToInsert], (err, result) => {
    if (err) throw err;
    console.log(`${result.affectedRows} records inserted successfully.`);


const sql="SELECT * FROM T_db.students";
con.query(sql,(err,results)=>{
    if(err) throw err;
    console.log("Student records:");
    console.table(results);
    con.end();
});
});
});
});