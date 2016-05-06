/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:04:22 by cjacques          #+#    #+#             */
/*   Updated: 2016/05/06 16:22:54 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

static double eval(char const *exp, int *p_err);
static double eval_expression(char const *exp, char const **pp_end, int *p_err);
static double eval_terme(char const *exp, char const **pp_end, int *p_err);
static double eval_puissance(char const *exp, char const **pp_end, int *p_err);
static double eval_facteur(char const *exp, char const **pp_end, int *p_err);
static char const *lstrip(char const *exp);
static void erreur_afficher(char const *message, char const *reste, int *p_err);

int main(int argc, char *argv[])
{
	int ret = 0;

	if (argc > 1)
	{
		int err = 0;
		int i = 1;

		while (argv[i] != NULL)
		{
			double resultat;

			printf("Evaluation de %s\n -> ", argv[i]);
			resultat = eval(argv[i], &err);
			if (err == 0)
			{
				printf("%g\n", resultat);
			}
			else
			{
				fprintf(stderr, "Une erreur a ete rencontree!!!\n");
				ret = EXIT_FAILURE;
			}
			i++;
		}
	}
	else
	{
		fprintf(stderr, "USAGE: tc \"exp1\" [\"exp2\" [...]]\n");
		ret = EXIT_FAILURE;
	}
	return ret;
}

static double eval(char const *exp, int *p_err)
{
	char const *p_end;
	double ret = eval_expression(exp, &p_end, p_err);

	if (*p_end != '\0')
	{
		erreur_afficher("Expression mal formee!", p_end, p_err);
	}
	return ret;
}

static double eval_expression(char const *exp, char const **pp_end, int *p_err)
{
	double ret = eval_terme(exp, pp_end, p_err);

	*pp_end = lstrip(*pp_end);
	while (**pp_end == '+' || **pp_end == '-')
	{
		char const *op = *pp_end;
		double terme = eval_terme(*pp_end + 1, pp_end, p_err);

		if (*op == '+')
		{
			ret += terme;
		}
		else
		{
			ret -= terme;
		}
		*pp_end = lstrip(*pp_end);
	}
	return ret;
}

static double eval_terme(char const *exp, char const **pp_end, int *p_err)
{
	double ret = eval_puissance(exp, pp_end, p_err);

	*pp_end = lstrip(*pp_end);
	while (**pp_end == '*' || **pp_end == '/')
	{
		char const *op = *pp_end;
		double puissance = eval_puissance(*pp_end + 1, pp_end, p_err);

		if (*op == '*')
		{
			ret *= puissance;
		}
		else if (puissance != 0.0)
		{
			ret /= puissance;
		}
		else
		{
			erreur_afficher("Division par zero", op, p_err);
		}
		*pp_end = lstrip(*pp_end);
	}
	return ret;
}

static double eval_puissance(char const *exp, char const **pp_end, int *p_err)
{
	double ret = eval_facteur(exp, pp_end, p_err);

	*pp_end = lstrip(*pp_end);
	if (**pp_end == '^' || strncmp(*pp_end, "**", 2) == 0)
	{
		int shift = (**pp_end == '^') ? 1 : 2;
		double puissance = eval_puissance(*pp_end + shift, pp_end, p_err);

		ret = pow(ret, puissance);
		*pp_end = lstrip(*pp_end);
	}
	return ret;
}

static double eval_facteur(char const *exp, char const **pp_end, int *p_err)
{
	double ret;

	exp = lstrip(exp);
	if (*exp == '(')
	{
		ret = eval_expression(exp + 1, pp_end, p_err);
		if (**pp_end != ')')
		{
			erreur_afficher("Parenthese fermante manquante", *pp_end, p_err);
		}
		else
		{
			(*pp_end)++;
		}
	}
	else
	{
		char *p_end = NULL;

		ret = strtod(exp, &p_end);
		*pp_end = p_end;
		if (*pp_end == exp)
		{
			erreur_afficher("Nombre invalide", *pp_end, p_err);
		}
	}
	return ret;
}

static void erreur_afficher(char const *message, char const *reste, int *p_err)
{
	printf("ERREUR: %s: %s\n", message, reste);
	if (p_err != NULL && *p_err == 0)
	{
		*p_err = 1;
	}
}

static char const *lstrip(char const *exp)
{
	if (exp != NULL)
	{
		while (isspace((unsigned char) *exp))
		{
			exp++;
		}
	}
	return exp;
}
