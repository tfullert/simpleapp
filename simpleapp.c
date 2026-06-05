#include <stdio.h>

// This code will be updated to trigger Actions
// This should be working.
// I needed to change RUNNER_TEMP_DIR to RUNNER_TEMP and I also needed to run a PowerShell command to base64 encode the .p12 file:
// [Convert]::ToBase64String([IO.File]::ReadAllBytes("C:\path_to_file\Certificate_pkcs12.p12")) | Set-Content -NoNewline -Encoding ascii "C:\path_to_file\Certificate_pkcs12.p12.b64"
// Make sure YAML file references SM_CLIENT_CERT_FILE properly (using env.SMCLIENT_CERT_FILE): SM_CLIENT_CERT_FILE: ${env.SM_CLIENT_CERT_FILE}
// Updated SM_HOST to include https://

// Getting an issue with the Client Auth Cert not working.

int main() {
    // Say "Hello" to the world!
    printf("Hello, World!\n");
    return 0;
}
