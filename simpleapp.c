#include <stdio.h>
#include <zlib.h>

// This code will be updated to trigger Actions
// I needed to change RUNNER_TEMP_DIR to RUNNER_TEMP and I also needed to run a PowerShell command to base64 encode the .p12 file:
// [Convert]::ToBase64String([IO.File]::ReadAllBytes("C:\path_to_file\Certificate_pkcs12.p12")) | Set-Content -NoNewline -Encoding ascii "C:\path_to_file\Certificate_pkcs12.p12.b64"
// Make sure YAML file references SM_CLIENT_CERT_FILE properly (using env.SMCLIENT_CERT_FILE): SM_CLIENT_CERT_FILE: ${env.SM_CLIENT_CERT_FILE}
// Updated SM_HOST to include https://
// NOTE: Needed to add CLIENT_CERT_FILE and CLIENT_CERT_FILE_PASSWORD environment variables? No...just make sure you specify ${{env.SM_CLIENT_CERT_FILE}} 

// NOTE: Each GitHub Actions step runs in its own process/shell so you need to export the SM_CLIENT_CERT_FILE value to be used on other steps:
//           echo "SM_CLIENT_CERT_FILE=${SM_CLIENT_CERT_FILE}" >> "$GITHUB_ENV"
// Getting an issue with the Client Auth Cert not working.
// Updating

int main() {
    // Say "Hello" to the world!
    printf("Hello, World!\n");
    printf("zlib version: %s\n", zlibVersion());
    return 0;
}
