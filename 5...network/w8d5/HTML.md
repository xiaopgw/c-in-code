day7
1.HTML
1.1. 开发环境：VScode
1.  在wwwroot路径下新建文件，文件命名为example.html

2. 安装库 open in browser
库安装完成后，在编写文本位置右击->open in other browser->选择合适的浏览器即可在网页显示html标签内容



输入html，选择html:5或者！回车可以将框架进行搭建


1.2. 简介
HTML（英文Hyper Text Markup Language的缩写）中文译为“超文本标记语言”。是用来描述网页的一种语言。
所谓超文本，因为它可以加入图片、声音、动画、多媒体等内容，不仅如此，它还可以从一个文件跳转到另一个文件，与世界各地主机的文件连接。
HTML 不是一种编程语言，而是一种标记语言 (markup language)
Web 浏览器的作用是读取 HTML 文档，并以网页的形式显示出它们。浏览器不会显示 HTML 标签，而是使用标签来解释页面的内容

1.3. 标签
1.3.1. 标签格式
1)有尖括号包围的关键字，如：<html>
2)通常成对存在，如：<body></body>
3)上面的标签前面是开始标签，后面是结束标签

1.3.2. 标签分类
1)单标签：也称空标签 <标签名 /> 如：<br/>
2)双标签：成对存在 <标签名> 内容 </标签名>

1.3.3. 常用标签
1)h1-h6标题标签
格式：<hn> 标题文本 </hn>
举例：
<h1>这是标题标签</h1>
<h2>这是标题标签</h2>
<h3>这是标题标签</h3>
<h4>这是标题标签</h4>
<h5>这是标题标签</h5>
<h6>这是标题标签</h6>

2)br换行标签
格式：<br>

3)p段落标签
一个段落中会根据浏览器窗口的大小自动换行
格式：<p> 文本内容 </p>

4)div标签：
是一个块级元素，可以把文档分割为独立的、不同的部分，可以在div中嵌套标签
举例：
<div class="news"> 
	 <h2>News headline 1</h2>
	 <p>some text. some text. some text...</p>
</div>
注：可以给div设置class或id，通过选择器设置属性，则内部成员具有相同属性

5)Input表单标签：
表示输入意思，是单标签
格式：<input type=”” name=”” value=”” id=””.....>

当type为text，表示是文本输入框
用法：<input type=”text” value=”文本框默认值” >
当type为radio，表示是单选框
用法：<input type=”radio” name=”控件名称” value=”提交的数值” onclick=”处理函数” >
解释：name：控件名称，同一组单选框设置相同名称
	 //Value：必须要有，是当点击时会提交的数据
	 Onclick:点击时会执行双引号中的处理函数
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>今天我想睡觉</title>
</head>

<body>
    <h1>这是标题标签</h1>
    <h2>这是标题标签</h2>
    <h3>这是标题标签</h3>
    <h4>这是标题标签</h4>
    <h5>这是标题标签</h5>
    <h6>这是标题标签</h6>
    全国基础教育工作会议7月22日在京召开。<br>
    会上传达了习近平总书记近日对基础教育工作作出的重要指示。<br>
    与会代表和广大教育工作者以及各界人士深受鼓舞、干劲更足。<br>
    大家表示，要以习近平总书记重要指示精神为指引，全面贯彻党的教育方针，<br>
    凝心聚力、奋发有为，为不断开创基础教育高质量发展新局面贡献力量 <br>

    用户名：<input type="text" name="usrname"> <br>
    密码：<input type="password"> <br>
    <input type="button" value="点击" onclick="get_info()"> <br>
    <!-- <input type="file"> -->

    男：<input type="radio" name="sex" id="man" onclick="fun(id)">
    女：<input type="radio" name="sex" id="woman" onclick="fun(id)">
</body>

<script>
    function fun(obj)
    {
        if(obj == 'man')
        {
            console.log("I am man")
        }
        else if(obj == 'woman')
        {
            console.log("I am woman")
        }
    }
    function get_info()
    {
        var v = document.getElementsByName("usrname");
        // v[0].value = "hello world"

        // 发送请求
        var xhr = new XMLHttpRequest(); // 创建XMLHttpRequest对象
        var url = ""
        xhr.open("post", url, true)
        xhr.send("get_modbus")

        // 接收回应
        xhr.onreadystatechange = function(){
            if(xhr.readyState == 4 && xhr.status == 200) // 请求完成并成功
            {
                // console.log(xhr.responseText);
                v[0].value = xhr.responseText
            }
        }
    }
</script>

</html>


课程回放：
录制：白昊天的个人会议室
日期：2026-07-24 08:43:48
录制文件：https://meeting.tencent.com/crm/KPjBEvQm00 

