#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>


displayresult(MYSQL *mysql, char *condition)
{
  char query[80];
  MYSQL_RES* res;
  MYSQL_ROW row;
  int i, fields;
  sprintf(query, "select * from user where %s",
	  condition);
  if (mysql_query(mysql, query)) {
    printf("MySQL Error %d: %s\n",
	   mysql_errno(mysql), mysql_error(mysql));
    exit(1);
  }
  res = mysql_use_result(mysql);
  fields = mysql_num_fields(res);
  printf("The students where %s are as follow.\n",
	 condition);
  while ((row = mysql_fetch_row(res))) {
    for (i = 0; i < fields; ++i) {
      printf("%12s ", row[i]);
    }
    printf("\n");
  }
  mysql_free_result(res);
}


int main()
{
  MYSQL mysql;
  MYSQL_RES* res;
  MYSQL_ROW row;
  int i, fields;
  mysql_init(&mysql);
  if (!mysql_real_connect(&mysql, "localhost", "root", "q", "study", 0, (char *)NULL, 0)) {
    printf("MySQL Error %d: %s\n",
	   mysql_errno(&mysql), mysql_error(&mysql));
    displayresult(&mysql, "user");
    exit(1);
  } 
}
