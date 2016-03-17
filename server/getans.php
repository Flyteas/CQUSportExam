<?php
$content_keyword = $_GET["kw"];
$mysql_server = '127.0.0.1'; //MYSQL服务器IP
$mysql_username = 'root'; //MYSQL用户名
$mysql_password = '123654'; //MYSQL密码
$mysql_dbname = 'CQU_SportExam'; //MYSQL数据库名
$conn = mysql_connect($mysql_server,$mysql_username,$mysql_password); //连接数据库
if(!$conn) //连接失败
{
	die('Error:' . mysql_error());
}
mysql_select_db($mysql_dbname, $conn);
mysql_query("set character set 'gbk'");   //设置字符集编码格式
$sqlstr = "SELECT * FROM subject where content like '$content_keyword'";
$result = mysql_query($sqlstr);                //得到查询结果数据集
//循环从数据集取出数据
while($row = mysql_fetch_array($result) )
{
    echo $row['content']."<br/>";
  /*  echo $row['type']."<br/>";
	if(!empty($row['option1']))
	{
		echo $row['option1']."<br/>";
	}
	if(!empty($row['option2']))
	{
		echo $row['option2']."<br/>";
	}	
	if(!empty($row['option3']))
	{
		echo $row['option3']."<br/>";
	}	
	if(!empty($row['option4']))
	{
		echo $row['option4']."<br/>";
	}	
	if(!empty($row['option5']))
	{
		echo $row['option5']."<br/>";
	}	
	if(!empty($row['option6']))
	{
		echo $row['option6']."<br/>";
	}*/
	echo $row['answer']."<br/><br/>";
}
mysql_close($conn);
?>
