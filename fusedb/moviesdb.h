/*
header file for movie database
*/

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>

mysqlpp::Query connect();

//get listing of movies
void getMovieListing(std::vector<std::string> &);

//get formatted data for given movie
void getMovieInfo(const char *,std::string &);

//add a rating to table
//parma1 = movie title
//param2 = comment
void addComment(std::string, std::string);


