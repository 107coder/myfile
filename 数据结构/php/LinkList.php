<?php 

class LinkList
{
	public $data;  //数据域
	public $next;  //指针域
	static $length;
	

	public function __construct($x){
		$this->data = $x;
		$this->next = null;
		self::$length = self::$length + 1 ;
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

	/**
	* @description: 根据位置在链表中查找一个值
	* @param {type} 
	* @return: 
	*/
function findSite($head,$n){
	if($n<1 || $n > LinkList::$length){
		echo "对不起，您的输入有错：请在1到".LinkList::$length.'的范围内！';
		return;
	}
	
	for($i=1;$i<$n;$i++){
		var_dump($head->data);
		$head = $head->next;
	}

	var_dump($head->data);

}
echo "<br/>";
findSite($head,2);

// var_dump($head);

