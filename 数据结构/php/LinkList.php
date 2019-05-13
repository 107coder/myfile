<?php 

class LinkList
{
	public $data;  //数据域
	public $next;  //指针域

	public function __construct($x){
		$this->data = $x;
		$this->next = null;
	}
}

$head = new LinkList(1); //创建一个头指针，头结点
$a = new LinkList(2); //创建第二个节点
$b = new LinkList(3); //创建第三个节点

$head->next = $a;
$a->next = $b;


//链式表的输出
while(true)
{
	echo $head->data."\n";
	$head = $head->next;
	// echo $a->data."\t";
	// echo $b->data."\t";	
	if($head->next == null){
		echo $head->data;
		break;
	} 
}

// var_dump($head);

