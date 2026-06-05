#include <stdio.h>

// This code will be updated to trigger Actions
// This should be working.
// I needed to change RUNNER_TEMP_DIR to RUNNER_TEMP and I also needed to run a PowerShell command to base64 encode the .p12 file:
// [Convert]::ToBase64String([IO.File]::ReadAllBytes("C:\path_to_file\Certificate_pkcs12.p12")) | Set-Content -NoNewline -Encoding ascii "C:\path_to_file\Certificate_pkcs12.p12.b64"

int main() {
    // Say "Hello" to the world!
    printf("Hello, World!\n");
    return 0;
}
