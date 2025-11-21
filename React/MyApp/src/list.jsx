import React from "react";

function ListItems(){
    const Items=["Apple","Banana","Orange","Mango","Cherry",];
    return(
        <ul>
            {Items.map((Items,index)=>(
                <li key={index}>{Items}</li>
            ))} 
        </ul>
    );
}
export default ListItems;