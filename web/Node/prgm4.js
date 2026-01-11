const con = require('./prgm1.js');
const sql="SELECT * FROM T_db.students";
con.query(sql,(err,results)=>{
    if(err) throw err;
    console.log("Student records:");
    console.table(results);
    con.end();
});
