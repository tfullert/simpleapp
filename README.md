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

In your repository, click on *Settings* --> *Secrets and Variables* --> *Actions*.
