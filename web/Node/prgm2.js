const con = require('./prgm1.js');
const cr_Tb =`
    CREATE TABLE IF NOT EXISTS
    T_db.students(
    rollno INT PRIMARY KEY,name VARCHAR(15))`;

con.query(cr_Tb,(err)=>{
    if(err) throw err;
    console.log('Table students created');
});

