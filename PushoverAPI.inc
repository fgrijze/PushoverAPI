<?php
/**
 * Pushover API
 *
 * @description Send a message via the Pushover API
 * @author Frank Grijze
 * @link https://www.yourwww.nl
 * @version 1.0.0
 */
class PushoverAPI {
	private array $availablePriorities = [
		"LOWEST" => -2,
		"LOW" => -1,
		"NORMAL" => 0,
		"HIGH" => 1,
		"EMERGENCY" => 2
	];
	private string $url = "https://api.pushover.net/1/messages.json";
	private string $appToken = "";
	private string $userKey = "";
	private string $message = "";
	private string $title = "";
	private string $priority = "NORMAL";
	private int $retry = 60;
	
	public function setAppToken ($appToken) {
		$this->appToken = $appToken;
	}
	
	public function getAppToken () {
		return $this->appToken;
	}
	
	public function setUserKey ($userKey) {
		$this->userKey = $userKey;
	}
	
	public function getUserKey () {
		return $this->userKey;
	}
	
	public function setMessage ($message) {
		$this->message = $message;
	}
	
	public function getMessage () {
		return $this->message;
	}
	
	public function setTitle ($title) {
		$this->title = $title;
	}
	
	public function getTitle () {
		return $this->title;
	}
	
	public function setPriority ($priority) {
		$this->priority = $priority;
	}
	
	public function getPriority () {
		return $this->priority;
	}
	
	public function setRetry ($retry) {
		$this->retry = $retry;
	}
	
	public function getRetry () {
		return $this->retry;
	}
	
	public function sendMessage () {
		$cURL = curl_init();
		
		curl_setopt_array($cURL, [
			CURLOPT_URL => $this->url,
			CURLOPT_RETURNTRANSFER => true,
			CURLOPT_POSTFIELDS => [
				"token" => $this->appToken,
				"user" => $this->userKey,
				"message" => $this->getMessage(),
				"title" => $this->getTitle(),
				"priority" => $this->availablePriorities[$this->getPriority()],
				"retry" => $this->getRetry(),
				"expire" => 10800,
				"sound" => false
			]
		]);
		
		$response = curl_exec($cURL);
		
		curl_close($cURL);
		
		$response = json_decode($response);
		
		if ($response->status != 1)
			throw new Exception($response->errors[0]);
	}
}
