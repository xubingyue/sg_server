<?php
	#九游php引入
	require_once dirname(dirname(__FILE__)).'/sg_sdk/jiuyou/jiuyou_sdk_service.php';	
	#当乐
	require_once dirname(__FILE__) . '/downjoy/dangle_sdk_service.php';


#--------------------登录验证接口---------------------------------
	global $veritfy_session_func;
	#苹果
	$veritfy_session_func[1]="";
	#九游
	$veritfy_session_func[2]="jiuyou_sdk_service::verifySession";
	#当乐
	$veritfy_session_func[3]="dangle_sdk_service::verifySession";
#--------------------end---------------------------------

?>
