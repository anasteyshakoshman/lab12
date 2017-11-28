#include <iostream>
#include <functional>
#include <future>
#include <thread>
#include <curl/curl.h>
void getCode(std::future<char*> & future)
{
    CURL * curl;
    long code = 0;
    CURLcode result;
    char * fut = future.get();
    curl = curl_easy_init();
    if (curl) 
    {
      curl_easy_setopt(curl, CURLOPT_URL, fut);
      curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
    }
    result = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, & code);
    std::cout << "Code of http : " << code << std::endl;
}
int main(int argc, char *argv[])
{
    char * url = argv[1];
    std::promise<char*> promise;
    std::future<char*> future = promise.get_future();
    std::thread thread (getCode, std::ref(future));
    promise.set_value(url);
    thread.join();
    return 0;
}
