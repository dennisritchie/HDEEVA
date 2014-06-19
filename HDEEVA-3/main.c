#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//http://curl.haxx.se/libcurl/c/http-post.html
#define __DATA__ "{\"contact_email\":\"nguyenthaithuanalg@gmail.com\", \"github_url\":\"https://github.com/karesansui/karesansui\"}"
int main(int argc, char *argv[]){

	  CURL *curl;
	  CURLcode res;
	    struct curl_slist *chunk = NULL;

	    chunk = curl_slist_append(chunk, "POST: /eva/001/endpoint HTTP/1.1");
	    chunk = curl_slist_append(chunk, "Authorization: Basic ZXZhbm9zcGFtQGhkZS5jby5qcDozNTQ4NzQ1OA==");
	    chunk = curl_slist_append(chunk, "Host: hdegip.appspot.com");
	    chunk = curl_slist_append(chunk, "Content-Type: application/json");
	    char * content_length = (char*) malloc(128);
	    memset(content_length, 0, 128);
	    sprintf(content_length, "Content-Length: %d", strlen(__DATA__));
	    chunk = curl_slist_append(chunk, content_length);

	  /* In windows, this will init the winsock stuff */
	  curl_global_init(CURL_GLOBAL_ALL);

	  /* get a curl handle */
	  curl = curl_easy_init();
	  if(curl) {
	    /* First set the URL that is about to receive our POST. This URL can
	       just as well be a https:// URL if that is what should receive the
	       data. */
	    curl_easy_setopt(curl, CURLOPT_URL, "http://hdegip.appspot.com/eva/001/endpoint");
	    /* Now specify the POST data */
	    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, __DATA__);
	    /* redo request with our own custom Accept: */
	    res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

	    /* Perform the request, res will get the return code */
	    res = curl_easy_perform(curl);
	    /* Check for errors */
	    if(res != CURLE_OK)
	      fprintf(stderr, "curl_easy_perform() failed: %s\n",
	              curl_easy_strerror(res));

	    /* always cleanup */
	    curl_easy_cleanup(curl);
	  }
	  curl_global_cleanup();
	return EXIT_SUCCESS;
}
