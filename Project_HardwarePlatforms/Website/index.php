<?php 
	$conexion=mysqli_connect('localhost','id19396675_jeremy','SQLdbjeremy2002%','id19396675_dbdustbin');
 ?>
<!DOCTYPE html>

<html lang="en">

<head>

    <meta charset="UTF-8">

    <meta http-equiv="X-UA-Compatible" content="IE=edge">

    <meta name="viewport" content="width=device-width, initial-scale=1">

    <title>Smart Dustbin</title>
    
      <!-- Latest compiled and minified CSS -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
	<!-- jQuery library -->
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>

	<!-- Latest compiled JavaScript -->
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    
    <script>
    var obj=null;
        function viewHide(id)
        {
            var targetId, srcElement, targetElement;
            var targetElement = document.getElementById(id);
            if (obj!=null) 
              obj.style.display='none';
            obj=targetElement;
            targetElement.style.display = "";
        }
    </script>
    

</head>

<body>
    <!--
    <form action="prueba_recibe.php" method="post">        

        <label>Device Label:</label>

        <input type="text" name="contar"><br>

        <label>Temperature:</label>                

        <input type="text" name="temperature"><br>

        <label>Humidity:</label>                        

        <input type="text" name="humidity"><br>

        <input type="submit" value="Send Data">
        

    </form>
    
    <p>*******************************************</p>
    -->
    <h2>Tacho De Basura Inteligente</h2>
    <p>Realizado por Jeremy Prieto</p>
    <p>Proyecto de la asignatura Plataformas de Hardware</p>
    <h2>Registros de recolleccion del tacho</h2>
    
    <hr>
    
    <h3>Ultimos 5 recientes registros</h3>
    <!--Tabla que muestra 5 datos recientes-->
    <table class="table table-striped">
        <thead>
	    <tr>
			<th>ID</th>
			<th>Estado</th>
			<th>Fecha</th>
		</tr>
		</thead>
    <?php 
        $query = "SELECT * FROM tacho ORDER BY idtacho DESC LIMIT 5";
        $result = mysqli_query($conexion,$query);
        
		while($row = mysqli_fetch_row($result)){
    ?>
    <tr>
	<td><?php echo $row[0] ?></td>
    <td><?php echo $row[1] ?></td>
    <td><?php echo $row[2] ?></td>
    </tr>
    <?php 
	}
	 ?>
    </table>
    
    <hr>
    <h3>Todos los registros</h3>
    <label>
        <input name="regdom" type="radio" Onclick="viewHide('tabla1')" value="A" >
    </label>
    <!--Tabla que muestra todos los datos de la tabla tacho-->    
    <table class="table table-striped" id='tabla1' style="display:none" width="100%">
        <thead>
	    <tr>
			<th>ID</th>
			<th>Estado</th>
			<th>Fecha</th>
		</tr>
		</thead>
    <?php 
        $query = "SELECT * FROM tacho;";
        $result = mysqli_query($conexion,$query);
        
		while($row = mysqli_fetch_row($result)){
    ?>
    <tr>
	<td><?php echo $row[0] ?></td>
    <td><?php echo $row[1] ?></td>
    <td><?php echo $row[2] ?></td>
    </tr>
    <?php 
	}
	 ?>
    </table>
    
</body>

</html>