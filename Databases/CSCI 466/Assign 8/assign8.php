<html>
<head>
    <title>Reinaldo Moraga (z1864815)</title>
</head>
<body>
    <a href="?listS=all">List all Suppliers</a>
    -
    <a href="?listP=all">List all Parts</a>
    <br/>
    <form>
	<input type="text" name="listS"/> SupplierList

	<input type="submit" value="Get Supplier Info!"/>
    </form>
<?php
include('userpass.php');
include('DrawTable.php');

	try {
		$dsn = "mysql:host=$servername;dbname=$dbname";
		$pdo = new PDO($dsn, $username, $password);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	}
	catch(PDOexception $e) {
		echo "Connection to database failed: " . $e->getMessage();
	}

	// 1. Shows all suppliers
	if (isset($_GET['listS'])) {
		if ($_GET['listS'] == 'all') {
			try {
				$rs = $pdo->query("SELECT * FROM S;");
				$rows = $rs->fetchAll(PDO::FETCH_ASSOC);
				echo "<b>Suppliers\n\n</b>";
				draw_table($rows);
			}
			catch(PDOexception $e) {
				echo "Query failed: " . $e->getMessage();
			}
		} else {
			// 4. User selects Supplier
			try {
				$sql="SELECT * FROM S, SP, P WHERE S.S = SP.S AND SP.P = P.P AND S.S=?";
				$rs = $pdo->prepare($sql);
				$rs->execute([$_GET['listS']]);
				$rows = $rs->fetchAll(PDO::FETCH_ASSOC);
				draw_table($rows);
			}
			catch(PDOexception $e) {
				echo "Query failed: " . $e->getMessage();
			}
		}	
	}		


	// 2. Shows all parts
	if (isset($_GET['listP'])) {
		if ($_GET['listP'] == 'all') {
			try {
				$rs = $pdo->query("SELECT * FROM P;");
				$rows = $rs->fetchAll(PDO::FETCH_ASSOC);
				echo "<b>\n\nParts\n\n</b>";
				draw_table($rows);		
			}	
			catch(PDOexception $e) {
				echo "Query failed: : " . $e->getMessage();
			}
		}
	}

	


?>
</body></html>
