<?hh // strict

/**
 * ReCaptcha Validation
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2015, Nathan Davies
 */

namespace ReCaptcha;

class ReCaptcha
{
	private bool $check, $result;
	private string $secret;

	/**
	 * Initiate
	 * @param string $secret App secret
	 */
	public function __construct(string $secret): void
	{
		$this->secret = $secret;
	}

	/**
	 * Is the user's input successful?
	 * @return bool
	 */
	public function isSuccess() : bool
	{
		return $this->verify();
	}

	/**
	 * Verify the ReCatpcha field
	 * @return bool
	 */
	public function verify(): bool
	{
		if (!$this->check)
		{
			$c = curl_init("https://www.google.com/recaptcha/api/siteverify");
			curl_setopt_array($c, array(
				CURLOPT_POST => 1,
				CURLOPT_POSTFIELDS => http_build_query(array(
					"secret" => $this->secret,
					"response" => $_POST["g-recaptcha-response"],
					"remoteip" => $_SERVER["REMOTE_ADDR"]
				)),
				CURLOPT_RETURNTRANSFER => true
			));

			$this->result = json_decode(curl_exec($c))->success;
			$this->check = true;
		}

		return $this->result;
	}
}
