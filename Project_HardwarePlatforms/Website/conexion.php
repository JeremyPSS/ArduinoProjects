<?php

class conexion{
   
    const user='id19396675_jeremy';
    const pass='SQLdbjeremy2002%';
    const db='id19396675_dbdustbin';
    const servidor='localhost';

    public function conectardb(){
        $conectar = new mysqli(self::servidor, self::user,self::pass,self::db);
        if($conectar->connect_errno){
            die("Error en la coneccion".$conectar->connect_error);
        }
        return $conectar;
    }   
}

?>