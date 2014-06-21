#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//http://curl.haxx.se/libcurl/c/http-post.html
#define __DATA__ "{\"contact_email\":\"nguyenthaithuanalg@gmail.com\", \"github_url\":\"https://github.com/dennisritchie/HDEEVA.git\"}"
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  int written = fwrite(ptr, size, nmemb, (FILE *)stream);
  fprintf(stderr, "%s", (char* ) ptr);
  return written;
}
int main(int argc, char *argv[]){

	  CURL *curl;
	  CURLcode res;
	  static const char *headerfilename = "head.out";
	FILE *headerfile;
	static const char *bodyfilename = "body.out";
	FILE *bodyfile;
	    struct curl_slist *chunk = NULL;

	    chunk = curl_slist_append(chunk, "POST: /eva/001/endpoint HTTP/1.1");
	    chunk = curl_slist_append(chunk, "Authorization: Basic bmd1eWVudGhhaXRodWFuYWxnQGdtYWlsLmNvbTo2MjQ5MjI2Mw==");
	    chunk = curl_slist_append(chunk, "Host: hdegip.appspot.com");
	    chunk = curl_slist_append(chunk, "Accept: */*");
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
	    /* send all data to this function  */
	    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	    /* Perform the request, res will get the return code */
	    /* open the files */
	     headerfile = fopen(headerfilename,"wb");
	     if (headerfile == NULL) {
	       curl_easy_cleanup(curl);
	       return -1;
	     }
	     bodyfile = fopen(bodyfilename,"wb");
	     if (bodyfile == NULL) {
	       curl_easy_cleanup(curl);
	       return -1;
	     }

	     /* we want the headers be written to this file handle */
	     curl_easy_setopt(curl,   CURLOPT_WRITEHEADER, headerfile);

	     /* we want the body be written to this file handle instead of stdout */
	     curl_easy_setopt(curl,   CURLOPT_WRITEDATA, bodyfile);
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
