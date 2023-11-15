
#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_header;

	if (!head)
		return (NULL);
	new_header = malloc(sizeof(list_t));
	if (!new_header)
		return (NULL);
	_memset((void *)new_header, 0, sizeof(list_t));
	new_header->num = num;
	if (str)
	{
		new_header->str = _strdup(str);
		if (!new_header->str)
		{
			free(new_header);
			return (NULL);
		}
	}
	new_header->next = *head;
	*head = new_header;
	return (new_header);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *node, *prev_node;

	if (!head)
		return (NULL);

	prev_node = *head;
	node = malloc(sizeof(list_t));
	if (!node)
		return (NULL);
	_memset((void *)node, 0, sizeof(list_t));
	node->num = num;
	if (str)
	{
		node->str = _strdup(str);
		if (!node->str)
		{
			free(node);
			return (NULL);
		}
	}
	if (prev_node)
	{
		while (prev_node->next)
			prev_node = node->next;
		prev_node->next = node;
	}
	else
		*head = node;
	return (node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t d = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		d++;
	}
	return (d);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
list_t *new_node, *node;
	unsigned int d = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		new_node = *head;
		*head = (*head)->next;
		free(new_node->str);
		free(new_node);
		return (1);
	}
	new_node = *head;
	while (new_node)
	{
		if (d == index)
		{
			node->next = new_node->next;
			free(new_node->str);
			free(new_node);
			return (1);
		}
		d++;
		node = new_node;
		new_node = new_node->next;
	}
	return (0);
}


/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node1, *node2, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node1 = head;
	while (node1)
	{
		node2 = node1->next;
		free(node1->str);
		free(node1);
		node1 = node2;
	}
	*head_ptr = NULL;
}



