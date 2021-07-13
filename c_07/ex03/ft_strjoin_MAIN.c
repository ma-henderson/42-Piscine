/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_MAIN.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:18:56 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/13 15:15:03 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*check_size(int size, char **strs)
{
	char *temp;
	
	if (size == 0)
	{
		temp = malloc(sizeof(char*));
		temp[0] = '\0';
		return (temp);
	}
	else
		temp = (char *)malloc(sizeof(strs));
	return (temp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int sum;
	int i;
	int j;
	int k;
	char *temp;

	temp = check_size(size, strs);
	if (!temp)
		return (temp);
	sum = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		k = 0;
		while (strs[i][j])
			temp[sum++] = strs[i][j++];
		if (i++ != size - 1)
			while (sep[k])
				temp[sum++] = sep[k++];
	}
	if (size != 0)
		temp[sum] = '\0';
	return (temp);
}

#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
int func_done = 0;
int timer_done = 0;

void *timer(void *var)
{
	var = 0x00;
	sleep(10);
	timer_done = 1;
	return (0);
}

void *execute(void *var)
{
	var = 0x00;

	char *strings[5] = {"AbuDhabi","42","Amazing","Piscine","Coding!!!"};
	char *seperator = "----------------";
	char *str;
	int size = 5;
	int i = 0;

	printf("size = %d | sep = %s | strings = ",size,seperator);
	for (i=0;i<size;i++)
		printf("\"%s\" ",strings[i]);
	str = ft_strjoin(size, strings, seperator);
	printf("\nReturn = %s",str);

	func_done = 1;
	return (0);
}
int main(void)
{
	pthread_t threadId;
	pthread_t timerId;
	int	threadId_Sig;

	threadId_Sig = pthread_create(&threadId, NULL, execute,  NULL);
	pthread_create(&timerId, NULL, timer, NULL);

	while (1) {
		if (timer_done) {
			pthread_cancel(threadId);
			printf("*** TIMEOUT ***\n");
			return (1);
		}
		if (func_done)
		{
			pthread_cancel(timerId);
			return (0);
		}
	}
	return (0);
}
