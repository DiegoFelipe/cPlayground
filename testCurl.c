#include <stdio.h>
#include <curl/curl.h>

int main (int argc, char ** argv)
{
    CURL *curlp;
    FILE *fp;
    int result;

    fp = fopen(argv[2], "wb");
    curlp = curl_easy_init();

    curl_easy_setopt(curlp, CURLOPT_URL, argv[1]);
    curl_easy_setopt(curlp, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curlp, CURLOPT_FAILONERROR, 1L);

    result = curl_easy_perform(curlp);

    if(result == CURLE_OK) {
        printf("Download successfuly \n");
    } else {
        printf("ERROR: %s\n", curl_easy_strerror(result));
    }

    fclose(fp);

    curl_easy_cleanup(curlp);

}