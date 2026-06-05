# Introduction
This a test to demonstrate the usage of DigiCert's Software Trust Manager (STM) and to show how easily STM can integrate with existing tools (in this case, Github Actions). To use this demo you will need to configure a keypair in STM and you will need to configure the authentication factors for the two-factor authentication used by the STM tools. To being, start by forking this repository into your Github account.

# Configure a keypair in STM
DigiCert's documentation for [creating a keypair](https://docs.digicert.com/en/software-trust-manager/keypairs/keypairs/create-static-keypair.html) in STM is very easy to follow. Configure your keypair as follows:

* Keypair Alias: <KEYPAIR NAME>
* Algorithm: RSA
* Size: 3072
* Category: Production
* Storage: Disk (Level 1)
* Keypair Status: Online
* Access: Restricted
* Allowed Users: <YOUR USER>
* Generate Certificate: <SELECTED>
* Keypair Validity: Match keypair and certificate expiry dates

Click on *Create Keypair* and make a note of the keypair alias you specified.

# Configure your factors for authentication
The tools that Github Actions will use to interact with STM require two-factor authentication. You will need to create an API key and a client authentication certificate. The documentation for [creating these factors](https://docs.digicert.com/en/software-trust-manager/get-started/requirements.html#two-factor-authentication-367442) is straightforward. Create the API key and client authentication certificate for the user you specified during the keypair creation above.

* [Create an API key](https://docs.digicert.com/en/software-trust-manager/get-started/requirements.html#create-an-api-key-367442)
* [Create a client authentication certificate](https://docs.digicert.com/en/software-trust-manager/get-started/requirements.html#create-a-client-authentication-certificate-367442)

The client authentication certificate will be downloaded as a .p12 file. Be sure to save it and the certificate password as they cannot be downloaded again once you close the modal dialog box.

# Configure the repository environment
This is arguably the hardest part because the DigiCert documentation for [Binary Signing with Github Actions](https://docs.digicert.com/en/software-trust-manager/ci-cd-integrations-and-deployment-pipelines/plugins/github/binary-signing-using-github-actions.html#get-started-with-digicert-binary-signing-1194271) is a little murky and has a few errors. But, most of the hard work has already been done and all you need to do at this point is configure variable and secret values.

In your repository, click on *Settings* --> *Secrets and Variables* --> *Actions*. Click on the *Variables* tab and then select the *Add repository variable* button. You will create the following variable:

* SM_HOST: https://clientauth.one.digicert.com (NOTE: Select the host for the [region](https://docs.digicert.com/en/software-trust-manager/get-started/requirements.html#host-environment-367442) you're using)

After saving the variable, now create your secrets by clicking on the *Secrets* tab and creating the following [session-based environment variables](https://docs.digicert.com/en/software-trust-manager/get-started/requirements/secure-credentials/set-up-secure-credentials-for-windows/session-based-environment-variables-for-windows.html#configure-session-based-environment-variables-470095) that you created in the STM portal previously:

* SM_API_KEY: [API_KEY_VALUE]
* SM_CLIENT_CERT_FILE: [BASE64_ENCODED_P12]
* SM_CLIENT_CERT_PASSWORD: [PASSWORD_VALUE]

For the SM_CLIENT_CERT_FILE you will need to first base64 encode the contents of the .p12 file. The way this works in the Github hosted-runner Actions is you copy this base64 version of the .p12 file to an environment variable and the runner/job will convert it back to a .p12 to be used by the runner.

