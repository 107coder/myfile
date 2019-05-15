<?php 
class LineList{
    const MAXSIZE = 100;
    private $arr;
    private $length;
    // public $data;
    // public $index;
    // public static $length=0;

    public function __construct($arr,$n){
        if($n>self::MAXSIZE){
            echo "对不起，数组的长度 $n 超出了内存空间：".self::MAXSIZE;
        }else if($n<0){
            echo "异常，长度不能为负数！";
        }else if($n == 0){
            echo "<br/>...你建立一张空表，数组的长度为0...<br/><br/>";
            $this->arr = $arr;
            $this->length = $n;
        }else{
            echo "<br/>...成功的建立了一张表...<br/><br/>";
            $this->arr = $arr;
            $this->length = $n;
        }
    }

    /**
     * @description: 按位查找，返回该位置上的值 
     * @param {type} 
     * @return: 
     */
    public function findValue($n){
        if($n<1 || $n > $this->length){
            return "您输入的位置$n 不正确，请在1到$this->length 的范围内！";
        }else{
            return "您要找的第$n 位的值为：".$this->arr[$n-1];
        }
    }
    /**
     * @description: 按值查找，返回值的地址 
     * @param $n 要查找的值
     * @return: string 
     */
    public function findSite($n){
        for($i=0; $i<$this->length; $i++){
            if($n == $this->arr[$i]){
                $b = $i+1;
                return "你要找的值 $n 对应的位置为$b";
            }else{
                $v = false;
            }

            if(!$v){
                return "你所找的值$n 不存在！";
            }
        }
    }
    /**
     * @description: 在规定的位置插入一个值
     * @param {type} 
     * @return: 
     */
    public function insertValue($i,$v){
        if($i<1 || $i > self::MAXSIZE){
            echo "插入的位置$i 不正确，请在1到".self::MAXSIZE."之间选择";
            return;
        }
        for($h=$this->length;$h>$i;$h--){
            $this->arr[$h] = $this->arr[$h-1];
        }
        if($i>$this->length){
            $this->arr[$this->length] = $v;
        }else{
            $this->arr[$i] = $v;
        }

        $this->length++;
        return $this->arr;
    }
    /**
     * @description: 根据位置删除一个值
     * @param {type} 
     * @return: 
     */
    public function deleteValue($i){
        if($i<1 || $i > $this->length){
            echo "您要删除的位置$i 不正确，请在1到".$this->length."之间选择";
            return;
        }
        for($j=$i;$j<$this->length;$j++){
            $this->arr[$j-1] = $this->arr[$j];
        }
        unset($this->arr[$this->length-1]);
        $this->length--;
        return $this->arr;
    }
    
    function __destruct(){
        if($this->length == 0){
            echo "<br>...销毁一张空表...<br/>";
        }else{
            $this->length = 0;
            echo "<br/>...成功销毁一张表...<br/>";
        }
    }


    public function showArr(){
        return $this->arr;
    }


}



/**执行操作*/

$arr = array(1,2,3,4,5,6);
$n = 6;

$line = new LineList($arr,$n);

echo $line->findValue(3).'<br/>';

echo $line->findSite(2)."<br/>";

echo "<pre>";
print_r($line->insertValue(4,200));
echo "</pre>";

echo "<pre>";
print_r($line->deleteValue(5));
echo "</pre>";