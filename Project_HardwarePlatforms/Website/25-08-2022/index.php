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
    
    
	
	<link href="style.css" rel="stylesheet" type="text/css" media="screen" />
	<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-gH2yIJqKdNHPEq0n4Mqa/HGKIhSkIHeL5AyhkYV8i59U5AR6csBvApHHNl/vI1Bx" crossorigin="anonymous">

    
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
        
        
        function reload(segs) {
            setTimeout(function() {
                location.reload();
            }, parseInt(segs) * 1000);
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
    <div class="p-3 bg-dark text-white">
        <div class="text-center">
            <h2 class="display-3">Tacho De Basura Inteligente</h2>
            <p class="blockquote-footer">Realizado por Jeremy Prieto</p>
            <p class="lead">Proyecto de la asignatura Plataformas de Hardware</p>
        </div>
    </div>
    
    
    <div class="container">
        <br>
        <h2 class="display-6 fw-normal">Registros de recolleccion del tacho</h2>
        <br>
        <hr>
        
        <h3>Ultimos 5 recientes registros</h3>
        <button type="button" class="btn btn-secondary" onclick="reload(1);">Recargar</button> 
        <br><br>
        <!--Tabla que muestra 5 datos recientes-->
        <table class="table table-dark table-hover">
            <thead>
    	    <tr>
    			<th class = "text-center">ID</th>
    			<th class = "text-center">Estado</th>
    			<th class = "text-center">Fecha</th>
    		</tr>
    		</thead>
        <?php 
            $query = "SELECT * FROM tacho ORDER BY idtacho DESC LIMIT 5";
            $result = mysqli_query($conexion,$query);
            
    		while($row = mysqli_fetch_row($result)){
        ?>
        <tr class = "text-center">
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
        <table class="table table-striped table-dark" id='tabla1' style="display:none" width="100%">
            <thead class="thead-dark">
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
    </div> <!--class container-->
    
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-A3rJD856KowSb7dwlZdYEkO39Gagi7vIsF0jrRAoQmDKKtQBHUuLZ9AsSv4jD4Xa" crossorigin="anonymous"></script>
    
</body>

</html>