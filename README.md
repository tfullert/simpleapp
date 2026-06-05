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

# Configure the repository environment
