<?php 
class LineList{
    const MAXSIZE = 100;
    public $data;
    public $index;
    public static $length=0;

    public function __construct($data){
        $this->data = $data;
        $this->index = null;
        self::$length++;
    }

    public function insertAt($index){
        $this->index = $index;
    }
}



//创建节点
$a = new LineList(1);
$b = new LineList(2);
$c = new LineList(3);
//插入节点
$a->insertAt(1);
$b->insertAt(2);
$c->insertAt(3);
//输出查看

$len = LineList::$length;

for($i=1;$i<=$len;$i++){
    
}