#include <iostream>
#include <string>
#include "utils.hpp"
using namespace std;

void getQuotesFromPage(){
  // Get all the quotes in a page

	// Parse html that just crawled
	parseHtml(buffer);

  // Todo: Find appropriate css selector for single quote
  char quote_selector_template[] = "body > div > div:nth-child(2) > div.col-md-8 > div:nth-child(%d) > span.text";
  char author_selector_template[] = "";
  char tag_selector_tempalte[] = "";
  char selector[MAX_URL_LEN];

  for(int i = 1; i <= 10; i++){
    // Todo: generate selector for quote and strip quote
    sprintf(selector, quote_selector_template, i);
    stripContent(selector);

    cout << stripped << endl;

    // Todo: generate selector for author and strip author
    // sprintf(selector, author_selector_template, i);
    // stripContent(selector);

    // cout << " --- " << stripped << endl;

    // Todo: Implement tags for your self!

    cout << endl;
  }
}

int main(){
  init();

  // Todo: Find appropriate url template for page enumeration
  int status, page = 1;
  char url_template[] = "https://quotes.toscrape.com/page/%d/";
  char url[MAX_URL_LEN];
  bool end;

  // Enumerate Page until End Condition
  do {
    // Using sprintf() and url_template to generate url
    sprintf(url, url_template, page);
    status = requestPage(url);

    if (status == 200)
      getQuotesFromPage();

    // Todo: Find end condition
    end = page >= 2;
  } while (!end && page++);

  return 0;
}