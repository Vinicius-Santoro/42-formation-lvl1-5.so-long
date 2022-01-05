/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:35:20 by ldatilio          #+#    #+#             */
/*   Updated: 2022/01/05 21:47:39 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# define BUFFER_SIZE 1
# define OPEN_MAX 256

/**	@brief	Description Write a function which returns a line read from a
 *			file descriptor.
 *	@param	fd	File descriptor to read from.
 *	@return	Read line: correct behavior. NULL if there is nothing else to read
 *			or an error occurred */
char	*get_next_line(int fd);

/* ********************************* Part 1 ********************************* */

//	is		********************************************************************

/**	@brief	Verifies if the character c is alphabetic.
 *	@param	c Character to be analysed
 *	@return int Returns true if c is alphabetical, else returns false.*/
int		ft_isalpha(int c);

/**	@brief	Verifies if the character c is a number.
 *	@param	c Character to be verified
 *	@return int Returns true if c is a number, else returns false.*/
int		ft_isdigit(int c);

/**	@brief Verifies if the character c is alphanumeric.
 *	@param c Character to be verified
 *	@return int Returns 1 if c is alphanumeric, else returns 0.*/
int		ft_isalnum(int c);

/**	@brief	Verify if the character typed is from the ASCII table.
 *	@param	c Character to be analysed
 *	@return	int Retuns 1 if character is found, and 0 if not found. */
int		ft_isascii(int c);

/**	@brief	Checks for any printable character including space.
 *	@param	c Character to be checked
 *	@return	int Returns 1 if character is printable, else returns 0.*/
int		ft_isprint(int c);

//	to		********************************************************************

/**	@brief	Converts uppercase character to lowercase.
 *	@param	c Character to be converted
 *	@return int Returns converted lowercase character.*/
int		ft_tolower(int c);

/**	@brief	Converts lowercase character to uppercase.
 * 	@param	c Character to be converted
 * 	@return int Returns converted uppercase character. */
int		ft_toupper(int c);

/**	@brief	converts the initial portion of the string pointed to by str to int.
 *	@param	str Pointer to the area of memory of the string to be converted
 *	@return int The converted value or 0 on error */
int		ft_atoi(const char *str);

//	mem		********************************************************************

/**	@brief	fills the first n bytes of the memory
 * 			area pointed to by s with the constant byte c.
 *	@param	s Pointer of memory area
 *	@param	c Constant byte to fill memory area
 *	@param	n Number of bytes to fill
 * 	@return	void* Returns a pointer to the memory area s */
void	*ft_memset(void *s, int c, size_t n);

/**	@brief	Set n bytes of s to 0.
 *	@param	s Pointer to the start of the memory location
 *	@param	n Buffer size */
void	ft_bzero(void *s, size_t n);

/**	@brief	Copies n bytes from memory area src to memory area dest.
 *	@param	dest	Destination pointer of memory area
 *	@param	src		Source pointer of memory area
 *	@param	n		Buffer size in bytes */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**	@brief	Copies no more than n bytes from memory area src to memory
 *  		area dest, stopping when the character c is found.
 * 			If the memory areas overlap, the results are undefined.
 * @param	dest	Destination pointer of memory area
 * @param	src		Source pointer of memory area
 * @param	c		Character to be searched
 * @param	n		Buffer size
 * @return	void* Returns pointer to the next character in dest after c,
 * 			or NULL if c was not found in the first n characters of src. */
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

/**	@brief	Copies n bytes from memory area src to memory area dest.
 *	@param	dest	Destination pointer of memory area
 *	@param	src		Source pointer of memory area
 *	@param	n		Buffer size in bytes
 *	@return	void* Returns a pointer to dest. */
void	*ft_memmove(void *dest, const void *src, size_t len);

/**	@brief	Scans the initial n bytes of the memory area
 *			pointed to by s for the first instance of c
 *	@param	s Pointer to the initial memory area
 *	@param	c Character to be searched
 *	@param	n Buffer size
 *	@return	Return a pointer str to the matching byte
 * 			or NULL if it does not occur */
void	*ft_memchr(const void *s, int c, size_t n);

/**	@brief	compares the first n bytes (each interpreted
 * 			as unsigned char) of the memory areas s1 and s2.
 *	@param	s1	Pointer to the first memory area to be compared
 *	@param	s2	Pointer to the second memory area to be compared
 *	@param	n	Buffer size in bytes
 *	@return	int Returns an integer less than, equal to, or greater than zero
 *  		if the first n bytes of s1 is found, respectively, to be less than,
 * 			to match, or be greater than the first n bytes of s2. */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//	strl	********************************************************************

/**	@brief	calculates the length of the string pointed to by s,
 * 			excluding the terminating null byte ('\0').
 *	@param 	s Pointer to the initial area of the string
 *	@return	size_t Returns the number of bytes in the string pointed to by s.*/
size_t	ft_strlen(const char *s);

/**	@brief	Copies up to size - 1 characters from
 * 			the NUL-terminated string src to dest, NUL-terminating the result.
 * @param	dest	Pointer to the destination area of memory
 * @param	src		Pointer to the source area of memory
 * @param	size	Buffer size in bytes
 * @return	size_t Returns the length of src. */
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);

/**	@brief	Appends the NUL-terminated string src to the end of dest.
 * 			It will append at most size - strlen(dest) - 1 bytes,
 * 			NUL-terminating the result.
 * @param 	dest	Pointer to the destination area of memory
 * @param 	src		Pointer to the source area of memory
 * @param 	size	Buffer size in bytes
 * @return 	size_t Return the total length of the string,
 * 			that is the initial length of dest plus the length of src.*/
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);

//	str		********************************************************************

/** @brief	Returns a pointer to the first occurrence
 * 			of the character c in the string s.
 * @param	s Pointer to the string memory area
 * @param	c Character to be searched inside the string s
 * @return	char* Return a pointer to the matched character
 * 			or NULL if the character is not found. */
char	*ft_strchr(const char *s, int c);

/**	@brief	Finds the end of the string `s`, then returns a pointer to the
 *			first occurrence of the character
 *			`c` in the string `s` by iterating backwards.
 *	@param	s Pointer to the string memory area
 *	@param	c Character to be searched inside the string s
 *	@return	char* Return a pointer to the matched character
 * 			or NULL if the character is not found. */
char	*ft_strrchr(const char *s, int c);

/**	@brief	Locates the first occurrence of the null-terminated string little in
 * 			the string big, where not more than `len` characters are searched.
 * 			Characters that appear after a `\\0` character are not searched.
 *	@param	big		String to be searched by `little`
 *	@param	little	String to search in `big`
 *	@param	len		Number of bytes to search
 *	@return	char* If little is an empty string, big is returned. If little
 *			occurs nowhere in big, NULL is returned. otherwise a pointer to the
 *			first character of the first occurrence of little is returned.*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**	@brief	Compares the two strings s1 and s2.
 *			The locale is not taken into account
 *	@param	s1	Pointer to the area of memory of the first string
 *	@param	s2	Pointer to the area of memory of the second string
 *	@param	n	Buffer size in bytes to compare both strings
 *	@return	int Return an integer less than, equal to, or greater than zero
 * 			if s1 (or the first n bytes thereof) is found, respectively,
 * 			to be less than, to match, or be greater than s2. */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//	malloc	********************************************************************

/**	@brief 	Allocates memory for an array of nmemb elements of size bytes each
 *			and returns a pointer to the allocated memory. The memory
 * 			is set to zero.
 *	@param	nmemb	Number of elements in array
 *	@param	size	Size of bytes for each element
 *	@return	void* Return a pointer to the allocated memory,
 *			which is suitably aligned for any built-in
 * 			type. On error, these functions return NULL. NULL may also
 * 			be returned by a successful call but with size 0. */
void	*ft_calloc(size_t nmemb, size_t size);

/**	@brief	Returns a pointer to a new string
 * 			which is a duplicate of the string s.
 *	@param	s1 Pointer to the start of the string do be copied
 *	@return	char* On success, returns a pointer to the
 * 			duplicated string. It returns NULL if insufficient memory was
 * 			available, with errno set to indicate the cause of the error.*/
char	*ft_strdup(const char *s1);

/* ********************************* PART 2 ********************************* */

// 	str		********************************************************************

/**	@brief	Allocates (with malloc(3)) and returns a substring from
 * 			the string ’s’. The substring begins at index ’start’
 * 			and is of maximum size ’len’.
 *	@param	s		The string from which to create the substring.
 *	@param	start	The start index of the substring in the string’s’.
 *	@param	len		The maximum length of the substring.
 *	@return char* Returns the substring. NULL if the allocation fails. */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**	@brief	Allocates (with malloc(3)) and returns a newstring,
 *			which is the result of the concatenationof ’s1’ and ’s2’.
 *	@param	s1 The prefix string
 *	@param	s2 The suffix string
 *	@return char* Returns the new string or NULL if the allocation fails. */
char	*ft_strjoin(char const *s1, char const *s2);

/**	@brief 	Allocates (with malloc(3)) and returns a copy of ’s1’
 * 			with the characters specified in ’set’ removed from
 * 			the beginning and the end of the string.
 *	@param	s1	The string to be trimmed
 *	@param	set	The set of characters to trim
 *	@return	char* Returns the trimmed string,
 *			or NULL if allocation fails. */
char	*ft_strtrim(char const *s1, char const *set);

/**	@brief	Allocates (with malloc(3)) and returns an array of strings
 * 			obtained by splitting ’s’ using the character ’c’ as a delimiter.
 *			The array must be ended by a NULL pointer.
 *	@param	s The string to be split
 *	@param	c The delimiter character
 *	@return char** Returns a matrix of two splitted arrays,
 *			else returns NULL if allocation fails. */
char	**ft_split(char const *s, char c);

/**	@brief	Allocates (with malloc(3)) and returns a string representing the
 *			integer received as an argument. Negative numbers must be handled.
 *	@param	n The integer to convert
 *	@return	char* Returns the string representing the integer.
 *			NULL if the allocation fails.*/
char	*ft_itoa(int n);

/**	@brief	Applies the function ’f’ to each character of the string ’s’
 *			to create a new string (with malloc(3)) resulting from
 *			successive applications of ’f’.
 *	@param	s The string on which to iterate
 *	@param	f The function to apply to each characte
 *	@return	char* The string created from the successive applications of ’f’.
 * 			Returns NULL if the allocation fails. */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**	@brief	Applies the function f to each character of the string passed as
 *			argument, and passing its index as first argument. Each character
 *			is passed by address to f to be modified if necessary.
 *	@param	The string on which to iterate.
 *	@param	The function to apply to each character.
 *	@return value None. */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// 	put		********************************************************************

/**	@brief	Outputs the character ’c’ to the given filedescriptor.
 *	@param	c	The character to output
 *	@param	fd	The file descriptor on which to write */
void	ft_putchar_fd(char c, int fd);

/**	@brief	Outputs the string ’s’ to the given filedescriptor.
 *	@param	s	The string to output
 *	@param	fd	The file descriptor on which to write */
void	ft_putstr_fd(char *s, int fd);

/**	@brief	Outputs the string ’s’ to the given filedescriptor,
 *			followed by a newline.
 *	@param	s	The string to output
 *	@param	fd	The file descriptor on which to write */
void	ft_putendl_fd(char *s, int fd);

/**	@brief Outputs the integer ’n’ to the given filedescriptor.
 *	@param n	The integer to output
 *	@param fd	The file descriptor on which to write */
void	ft_putnbr_fd(int n, int fd);

/* ********************************* BONUS ********************************** */

/**	@brief	Allocates and returns a new element of t_list. with the value of
 * 			CONTENT and the variable NEXT is initialized to NULL.
 *	@param	content the string to be created to the new t_list.
 *	@return	returns the address of the new t_list element. */
t_list	*ft_lstnew(void *content);

/**	@brief	Add a new element to the start of the linked list appointed by lst.
 *	@param	lst list of address of t_lists.
 *	@param	new elemt to be add to the start of the LST. */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**	@brief	find the length of the linked list appointed by LST
 *	@param	lst linked list to be count.
 *	@return	length of LST */
int		ft_lstsize(t_list *lst);

/**	@brief	find the last element of the linked list.
 *	@param	lst address of a linked list.
 *	@return	the address of the linked list. */
t_list	*ft_lstlast(t_list *lst);

/**	@brief	add a new element to the linked list in the end.
 *	@param	lst appointed a linked list.
 *	@param	new the new element to be added. */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**	@brief	aplies the function DEL to the LST and them free the LST.
 *	@param	lst linked element to be deleted and free.
 *	@param	del function to delete the element. */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**	@brief	applies the del function to the all elements of the linked list and
 * 			the free all
 *	@param	lst list be clear and deleted.
 *	@param	del functions to delete the elements. */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**	@brief	Iterates the list ’lst’ and applies the function ’f’ to the content
 * 			of each element.
 *	@param	lst The address of a pointer to an element.
 *	@param	f	The address of the function used to iterate on the list. */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**	@brief	Iterates the list ’lst’ and applies the function ’f’ to the content
 * 			of each element. Creates a new list resulting of the successive
 * 			applications of the function ’f’.
 *	@param	lst The address of a pointer to an element.
 *	@param	f	The address of the function used to iterate on the list.
 *	@param	del The address of the function used to delete the content of an
 * 			element if needed.
 *	@return	The new list. NULL if the allocation fails. */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
