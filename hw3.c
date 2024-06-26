/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hw3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:39:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/04/17 14:15:44 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
 * 1.
 *  (2) 원형 연결 리스트 - 마지막 노드가 처음을 가리키므로 NULL 을 가리키는 포인터가 없다.
 * 2.
 *  (1) 배열 - 연결 리스트와 다르게 n 번째 인덱스에 바로 arr[n] 과 같이 접근이 가능하다. 연결 리스트는 각 리스트가 병렬적으로 연결되어
 *  traverse 가 필요함.
 * 3.
 *  (3) last->link == NULL
 *   - 포인터 last 가 마지막 노드를 가리킨다. last 의 노드와 그 데이터는 유효하고,
 *   last->link == null 을 가리킴으로 연결리스트가 끝날 것이다. last->link->link 는 null->link 를 뜻하고 이는 참조 불가능
 * 4.
 *  (c) p = p->link
 *   p를 참조하면 어떤 노드가 나올 것이고, 그것의 다음 노드는 그의 link 를 참조하면 된다.
 * 5. p = p-> link;
 * 6. q = p;
 * 7. D
 *  - p = list->head 로 시작해, p->data = D 까지 p = p->link 로 움직입니다. 이 위치에서 p->link = NULL 이기 때문에
 *  반복문을 탈출합니다. 따라서 실행 후 p->data = D 를 가리키고 있습니다.
 *
 * 9번부터는 코드로 작성
 */

//9
typedef struct s_list{
	int data;
	struct s_list *link;
}t_list;

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->data = content;
		new->link = NULL;
	}
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (!(lst) || !(new))
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp && tmp->link)
		tmp = tmp->link;
	tmp->link = new;
}
//
//int main(){
//	int numList;
//	int num;
//	t_list *head;
//
//	printf("노드의 개수 : ");
//	scanf("%d", &numList);
//	for (int i = 1; i < numList + 1; i++) {
//		printf("노드 #%d 데이터 : ", i);
//		scanf("%d", &num);
//		ft_lstadd_back(&head, ft_lstnew(num));
//	}
//	t_list *tmp = head;
//	printf("생성된 연결 리스트: ");
//	for (int i = 1; i < numList + 1; i++) {
//		printf("%d", tmp->data);
//		if (i != numList)
//			printf("->");
//		tmp = tmp->link;
//	}
//} // main for 9

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	if (!lst)
		return (0);
	cnt = 1;
	while (lst->link)
	{
		cnt++;
		lst = lst->link;
	}
	return (cnt);
} // used in 10

//int main(){
//	int numList;
//	int num;
//	t_list *head;
//
//	printf("노드의 개수 : ");
//	scanf("%d", &numList);
//	for (int i = 1; i < numList + 1; i++) {
//		printf("노드 #%d 데이터 : ", i);
//		scanf("%d", &num);
//		ft_lstadd_back(&head, ft_lstnew(num));
//	}
//	t_list *tmp = head;
//	printf("연결 리스트 노드의 개수 = %d", ft_lstsize(head));
//} // main for 10

//int main(){
//	int numList;
//	int num;
//	t_list *head;
//	int sum = 0;
//
//	printf("노드의 개수 : ");
//	scanf("%d", &numList);
//	for (int i = 1; i < numList + 1; i++) {
//		printf("노드 #%d 데이터 : ", i);
//		scanf("%d", &num);
//		ft_lstadd_back(&head, ft_lstnew(num));
//	}
//	t_list *tmp = head;
//	for (int i = 1; i < numList + 1; i++) {
//		sum += tmp->data;
//		tmp = tmp->link;
//	}
//	printf("연결 리스트의 데이터 합: %d", sum);
//} // main for 11

int ft_lstapp(t_list *lst, int key){
	int appear = 0;
	while(lst){
		if (lst->data == key)
			appear++;
		lst = lst->link;
	}
	return appear;
} //used in 12

//int main(){
//	int numList;
//	int num;
//	t_list *head;
//	int key;
//
//	printf("노드의 개수 : ");
//	scanf("%d", &numList);
//	for (int i = 1; i < numList + 1; i++) {
//		printf("노드 #%d 데이터 : ", i);
//		scanf("%d", &num);
//		ft_lstadd_back(&head, ft_lstnew(num));
//	}
//	printf("탐색할 값을 입력하시오: ");
//	scanf("%d", &key);
//	int app = ft_lstapp(head, key);
//	printf("%d는 연결 리스트에서 %d 번 나타납니다.", key, app);
//} //  main for 12

void ft_lstdelKey(t_list **lst, int key){
	t_list *tmp = *lst;
	t_list *prev = NULL;
	if (!lst)
		return;
	while (tmp) {
		if (tmp->data == key) {
			if (prev == NULL) {
				t_list *next = tmp->link;
				free(tmp);
				tmp = next;
			} else {
				t_list *next = tmp->link;
				free(tmp);
				prev->link = next;
				tmp = next;
			}
		} else {
			prev = tmp;
			tmp = tmp->link;
		}
	}
}//PROBLEM UNSOLVED!!!!

int main(){
	int numList;
	int num;
	t_list *head;
	int key;

	printf("노드의 개수 : ");
	scanf("%d", &numList);
	for (int i = 1; i < numList + 1; i++) {
		printf("노드 #%d 데이터 : ", i);
		scanf("%d", &num);
		ft_lstadd_back(&head, ft_lstnew(num));
	}
	printf("삭제할 값을 입력하시오: ");
	scanf("%d", &key);
	ft_lstdelKey(&head, key);
	t_list *tmp = head;
	printf("생성된 연결 리스트: ");
	for (int i = 1; i < numList + 1; i++) {
		printf("%d", tmp->data);
		if (i != numList)
			printf("->");
		tmp = tmp->link;
	}
} // main for 9
