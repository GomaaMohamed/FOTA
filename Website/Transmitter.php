<?php

$handle = fopen("uploads/hexfile.txt", "r");
$counter=10;
$End=0;
/* open the file in write mode*/
	$myfile=fopen("status.txt","w");
	fwrite($myfile,"   ");
	fclose($myfile);
	
	
while (1) 
{
	/* open the file in write mode*/
	$myfile=fopen("status.txt","r");
	$value=fgets($myfile);
	if($value=='ok')
	{
		$record = fopen("Record.txt", "w");
		while($counter--)
		{
			
		
			if(($line = fgets($handle)) == false)
			{
				$End=1;
				break;
			}
			//$line = fgets($handle);
			echo "$line"."<br>";
			fwrite($record,$line);// process the line read.
			
		}
		if($End==1)break;
		fclose($record);
			
		fclose($myfile);
		$myfile=fopen("status.txt","w");
		fwrite($myfile,"   ");
		//fclose($myfile);
		
		
	}
	fclose($myfile);
	$counter=10;
	
}

?>
