<?php

    //require_once('conexion.php');
    include'conexion.php';
    //echo "***YO RECIBO DATOS*** <br>";

    //read data from index.html
    $contar = $_POST['contar'];
    echo "#contar =".$contar;
    //$temperature = $_POST['temperature'];
    //$humidity = $_POST['humidity'];    
    
    //insert data from varibles
    $conn = new conexion();
    $query = "INSERT INTO tacho(contar,fecha) VALUES($contar,NOW())";
    $insert = mysqli_query($conn->conectardb(),$query);
    if ($insert){
            echo " Registo en base de datos OK! ";
            echo $contar." <- se ha registrado";
    } else {
        echo " Falla! Registro BD";
    }
    

    //print data from db
    $query = "SELECT * FROM tacho where idtacho=5;";
    $result = mysqli_query($conn->conectardb(),$query);
    $row = mysqli_fetch_row($result);
    
    //echo "{envio:".$device."}";
    echo "IdTacho: ".$row[0].", contar: ".$row[1].", fecha: ".$row[2]; 

?>