<?php 

class LinkList
{
	public $data;
	public $next;

	public function __construct($x){
		$this->data = $x;
		$this->next = null;
	}
}

$head = new LinkList(1);
$a = new LinkList(2);
$b = new LinkList(3);

$head->next = $a;
$a->next = $b;

if($head->next != null)
{
	echo $head->data."\n";
	echo $a->data."\t";
	echo $b->data."\t";	
}

