<?php
  $a=32.1;
  echo "轉換前: a=$a <br>";
  $a=(int)$a;
  echo "轉換後: a=$a <br>";
  echo "變數 a 的屬性 : ";
  var_dump($a);
  echo "<p>";
  $b=12;
  echo "轉換前: b=$b <br>";
  $b=(int)($b/5);
  echo "轉換後: b=$b <br>";
  echo "變數 b 的屬性 : ";
  var_dump($b);
  echo "<p>";
  $c=12.3;
  echo "轉換前: c=$c <br>";
  $c=(string)$c;
  echo "轉換後: c=$c <br>";
  echo "變數 c 的屬性 : ";
  var_dump($c);
  echo "<p>";
  $d="12345";
  echo "轉換前: d=$d <br>";
  $d=(int)$d;
  echo "轉換後: d=$d <br>";
  echo "變數 d 的屬性 : ";
  var_dump($d);
  echo "<p>";
?>