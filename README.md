# recaptcha
Simple ReCaptcha validation script for Hack Lang (HH)

# Usage
First, you'll need to register keys for your site at https://www.google.com/recaptcha/admin

When your app receives a form submission containing the g-recaptcha-response field, you can verify it using:

```php
if ((new ReCaptcha("SECRET"))->verify()) {
    // whoop whoop
} else {
    // dang it
}
```
