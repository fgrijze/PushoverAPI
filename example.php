<?php
require "PushoverAPI.inc";

$Pushover = new \PushoverAPI();

$Pushover->setAppToken(""); // Enter your app token
$Pushover->setUserKey(""); // Enter your user key

$Pushover->setMessage("This message is for testing purpose only."); // Enter the message

try {
	$Pushover->sendMessage();
	
	echo "Message sent!";
}
catch (Exception $e) {
	echo "Unable to send message ({$e->getMessage()})";
}
