<!DOCTYPE html>
<html>
<body>

<h1>狼人杀选职业器</h1>

<?php
$name=array("汉堡","超级小导","feelmelove","飞飞","秦","香辣牛筋","爱笙","可莉来咯");
$file=fopen("zy.txt","r");
$i=0;
echo "志愿:"."<br>";
while(!feof($file)){
    echo $name[$i].":".fgets($file)."<br>";
    $i=$i+1;
}
fclose($file);
?>
<form action="solve.php" method="post">
<select name="uname">你是谁？
<option value="汉堡">汉堡</option>
<option value="超级小导">超级小导</option>
<option value="freemelove">freemelove</option>
<option value="飞飞">飞飞</option>
<option value="秦">秦</option>
<option value="香辣牛筋">香辣牛筋</option>
<option value="爱笙">爱笙</option>
<option value="可莉来咯">可莉来咯</option>
</select>
<select name="zy1">第一志愿
<option value="无">无</option>
<option value="船长">船长</option>
<option value="工程">工程</option>
<option value="厨子">厨子</option>
<option value="医生">医生</option>
<option value="牧师">牧师</option>
<option value="猎人">猎人</option>
<option value="枪手">枪手</option>
<option value="导航">导航</option>
</select>
</select>
<select name="zy2">第二志愿
<option value="无">无</option>
<option value="船长">船长</option>
<option value="工程">工程</option>
<option value="厨子">厨子</option>
<option value="医生">医生</option>
<option value="牧师">牧师</option>
<option value="猎人">猎人</option>
<option value="枪手">枪手</option>
<option value="导航">导航</option>
</select>
</select>
<select name="zy3">第三志愿
<option value="无">无</option>
<option value="船长">船长</option>
<option value="工程">工程</option>
<option value="厨子">厨子</option>
<option value="医生">医生</option>
<option value="牧师">牧师</option>
<option value="猎人">猎人</option>
<option value="枪手">枪手</option>
<option value="导航">导航</option>
</select>
<input type="submit" value="设置志愿">
</form>
</body>
</html>