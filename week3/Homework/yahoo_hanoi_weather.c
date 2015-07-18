#include <stdio.h>
int main()
{
printf("Clear\n");
printf("%-2d %d\n",85,74);
printf("80\n\n");
printf("Forecast\n");
printf("%-15s %-2d %d\n","Today",85,74);
printf("%-15s %-2d %d\n","Tomorrow",87,75);
printf("%-15s %-2d %d\n","Friday",85,74);
printf("%-15s %-2d %d\n","Saturday",88,74);
printf("%-15s %-2d %d\n\n","Sunday",90,73);
printf("Details\n");
printf("%-2s%-10d","Feels Like",89 );
printf("%-2s%-10s","Visibility","--mi" );
printf("%-2s%d%-10s","humidity",94,"%" );
printf("%-2s%d%s","UV Index",0,"(low)" );printf("\n");
printf("Tonight - Party cloudy.Low 74F(23.3C).Winds Light and variable\n");
printf("Tomorrow - Variable clouds with scattered thunderstorms.High 87F(30.6C).\nWinds SE at 5 to 10 mph (8.0 to 16.1 kph). Chance of rain 60%%\n\n");
printf("%-18s%-25s %-16s%s\n","Sunrise: 5:40 AM","Sunset: 6.11 PM","Wind : 2mph NW","Barameter: 29.67 in");



	return 0;
}