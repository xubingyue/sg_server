<?php
	header('Content-type: application/json');
	require_once dirname(dirname(__FILE__)).'/sg_sdk/sdk_func.php';

	#获取post参数
	$params = array();
	$post_str=file_get_contents("php://input");
	$paramsArr = explode('&',$post_str); 
	foreach($paramsArr as $k=>$v) 
	{ 
		$a = explode('=',$v); 
		$params[$a[0]] = $a[1]; 
	} 

	#$channel_id=isset($params["channel_id"])?$params["channel_id"]:-1;
	#$function=isset($params["function"])?$params["function"]:"no function";

	$channel_id=isset($_GET["channel_id"])?$_GET["channel_id"]:-1;
	$function=isset($_GET["function"])?$_GET["function"]:"no function";

	$result = array();
	$result["status"]="failed";	
	$result["message"]->code="-1";	
	$result["message"]->msg="unknow error";	

	#登录
	do {
		if ( $channel_id == -1 ){
			$result["message"]->code="-2";	
			$result["message"]->msg="channel_id is null";	
			break;
		}
		
		if ( !isset($veritfy_session_func[$channel_id]) ){
			$result["message"]->code="-3";	
			$result["message"]->msg="channel_id:[".$channel_id."],veritfy_session_func is not set";	
			break;
		}

		if ( !is_callable($veritfy_session_func[$channel_id]) ){
			$result["message"]->code="-5";	
			$result["message"]->msg="channel_id:[".$channel_id."],veritfy_session_func is not exist";	
			break;
		}

		#登录验证
		if ( $function == "veritfy_session" ) {
			$sid = "sst1game68de1f57973e4954b12d8bfee35bb976123265";
			$exec_func=$veritfy_session_func[$channel_id];
			$result = call_user_func( $exec_func, $sid );
			break;
		}else{
			$result["message"]->code="-4";	
			$result["message"]->msg="function {$function} undefined";	
			break;
		}
	}while(0);

	$result = preg_replace_callback("#\\\u([0-9a-f]{4})#i",function($matchs){ return iconv('UCS-2BE', 'UTF-8', pack('H4', $matchs[1])); }, json_encode($result));

	echo $result;
?>
