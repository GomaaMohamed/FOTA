<?php
if (isset($_POST['submit']))
{
	$file=$_FILES['file'];
	
	$fileName   =$_FILES['file']['name'];
	$fileTmpName=$_FILES['file']['tmp_name'];
	$fileSize   =$_FILES['file']['size'];
	$fileError  =$_FILES['file']['error'];
	$fileType   =$_FILES['file']['type'];
	
	$fileExt = explode('.',$fileName) ; 
	$fileActualExt = strtolower(end($fileExt));
	
	$allowed = array('hex' , 'elf' );
	
	if(in_array($fileActualExt, $allowed))
	{
		if ($fileError === 0)
		{
			if ($fileSize < 100000)
			{  
				// Deleting all the files inside the given folder 
				array_map('unlink', array_filter( 
				(array) array_merge(glob("uploads/*")))); 
  
				// Rename the new file and save it alone in "uploads" folder
				$fileNameNew = "hexfile"."."."txt" ;
				$fileDestination='uploads/'.$fileNameNew;
				move_uploaded_file($fileTmpName, $fileDestination);
				header("Location: Transmitter.php");
				
			}
			else
			{
				echo "Your file is too big" ;
			}
			
		}
		else
		{
				echo "Error Uploading your file " ;
		}
	}
	else
	{
		echo "Invalid file type" ;
	}

}
