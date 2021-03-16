#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int
main (int argc, char *argv[])
{
  int peoplen = 0;
  printf ("Enter the number of people: ");
  scanf ("%d", &peoplen);
  printf ("Number of people = %d\n", peoplen);

  char choice[5][10] = { "Kebab", "Burger", "Pasta", "Lahmacun", "Salad" };
  int points[5] = { 0, 0, 0, 0, 0 };
  int choicen = 5;


  for (int i = 0; i < peoplen; i++)
    {
      if (i + 1 == 1)
	{
	  printf ("1st person");
	}
      else if (i + 1 == 2)
	{
	  printf ("2nd person");
	}
      else if (i + 1 == 3)
	{
	  printf ("3rd person");
	}
      else
	{
	  printf ("%dth person", i + 1);
	}
      printf (", give a preference up to %d.\n", choicen);
      int preferences[choicen];
      for (int j = 0; j < choicen; j++)
	{

	  while (true)
	    {
	      printf ("%d. Give your preference for %s: ", j + 1, choice[j]);
	      scanf ("%d", &preferences[j]);
	      bool unique = true;
	      for (int k = 0; k < j; k++)
		{
		  if (preferences[j] == preferences[k])
		    {
		      unique = false;
		      break;
		    }
		}
	      if (preferences[j] <= choicen && 1 <= preferences[j] && unique)
		{
		  int temp = points[j];
		  int point = choicen + 1 - preferences[j];
		  points[j] = temp + point;
		  printf
		    ("%d point added to %d with preference %d, total points are %d.\n",
		     point, temp, preferences[j], points[j]);
		  break;
		}
	    }
	}
    }

  int treshold = 10;
  int count = 0;
  for (int i = 0; i < choicen; i++)
    {
      if (points[i] >= treshold)
	{

	  count++;
	}
    }
  printf ("Number of choices above the treshold %d: %d\n", treshold, count);
  if (count <= 0)
    {
      printf ("You are eating at home/dorm today!");
    }
  int c = 0;
  for (int i = 0; i < choicen && c < count; i++)
    {
      if (points[i] >= treshold)
	{
	  strcpy (choice[c], choice[i]);
	  int temp = points[i];
	  points[c] = temp;
	  printf ("%d. %s\n", c + 1, choice[c]);
	   points[c]=0;
	  c++;
	}
    }
  choicen = count;


  for (int i = 0; i < peoplen; i++)
    {
      if (i + 1 == 1)
	{
	  printf ("1st person");
	}
      else if (i + 1 == 2)
	{
	  printf ("2nd person");
	}
      else if (i + 1 == 3)
	{
	  printf ("3rd person");
	}
      else
	{
	  printf ("%dth person", i + 1);
	}
      printf (", give a preference up to %d.\n", choicen);
      int preferences[choicen];
      for (int j = 0; j < choicen; j++)
	{

	  while (true)
	    {
	      printf ("%d. Give your preference for %s: ", j + 1, choice[j]);
	      scanf ("%d", &preferences[j]);
	      bool unique = true;
	      for (int k = 0; k < j; k++)
		{
		  if (preferences[j] == preferences[k])
		    {
		      unique = false;
		      break;
		    }
		}
	      if (preferences[j] <= choicen && 1 <= preferences[j] && unique)
		{
		  int temp = points[j];
		  int point = choicen + 1 - preferences[j];
		  points[j] = temp + point;
		  printf
		    ("%d point added to %d with preference %d, total points are %d.\n",
		     point, temp, preferences[j], points[j]);
		  break;
		}
	    }
	}
    }
  int max = 0;
  for (int i = 0; i < choicen; i++)
    {
      if (points[i] > max)
	{
	  max = points[i];
	  strcpy (choice[0], choice[i]);
	}
    }
  if (0 < choicen)
    {
      printf ("%s will be ordered.\n", choice[0]);
    }
  return 0;
}
