<?php
  $a=32.1;
  echo "轉換前: a=$a 為float<br>";
  settype($a,integer);
  echo "轉換後: a=$a <br>";
  echo "變數 a 的屬性 : ";
  var_dump($a);
  echo "<p>";
  $b=12.3;
  echo "轉換前: b=$b 為float<br>";
  settype($b,string);
  echo "轉換後: b=$b <br>";
  echo "變數 b 的屬性 : ";
  var_dump($b);
  echo "<p>";
  $c="12345";
  echo "轉換前: c=$c 為string<br>";
  settype($c,integer);
  echo "轉換後: c=$c <br>";
  echo "變數 c 的屬性 : ";
  var_dump($c);
  echo "<p>";
  $d="123.45";
  echo "轉換前: d=$d 為string<br>";
  $e=settype($d,float);
  echo "轉換後: d=$d <br>";
  echo "變數 d 的屬性 : ";
  var_dump($d);
  echo "<br>函數回傳值為 $e";
  echo "<p>";
?>