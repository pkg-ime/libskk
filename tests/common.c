#include <unistd.h>
#include <libskk/libskk.h>
#include "common.h"

SkkContext *
create_context (gboolean use_user_dict,
                gboolean use_file_dict)
{
  SkkDict *dictionaries[2];
  gint n_dictionaries = 0;
  SkkUserDict *user_dict = NULL;
  SkkFileDict *file_dict = NULL;
  SkkContext *context;
  GError *error;

  unlink ("user-dict.dat");

  if (use_user_dict) {
    error = NULL;
    user_dict = skk_user_dict_new ("user-dict.dat", "EUC-JP", &error);
    g_assert_no_error (error);
    dictionaries[n_dictionaries++] = SKK_DICT (user_dict);
  }

  if (use_file_dict) {
    error = NULL;
    file_dict = skk_file_dict_new (LIBSKK_FILE_DICT, "EUC-JP", &error);
    g_assert_no_error (error);
    dictionaries[n_dictionaries++] = SKK_DICT (file_dict);
  }

  context = skk_context_new (dictionaries, n_dictionaries);

  if (user_dict)
    g_object_unref (user_dict);
  if (file_dict)
    g_object_unref (file_dict);

  return context;
}

void
check_transitions (SkkContext    *context,
                   SkkTransition *transitions,
                   int            n_transitions)
{
  gint i;

  for (i = 0; i < n_transitions; i++) {
    const gchar *preedit, *output;
    SkkInputMode input_mode;
    skk_context_reset (context);
    output = skk_context_poll_output (context);
    g_free (output);

    skk_context_set_input_mode (context, transitions[i].input_mode);
    skk_context_process_key_events (context, transitions[i].keys);
    preedit = skk_context_get_preedit (context);
    g_assert_cmpstr (preedit, ==, transitions[i].preedit);
    output = skk_context_poll_output (context);
    g_assert_cmpstr (output, ==, transitions[i].output);
    g_free (output);
    input_mode = skk_context_get_input_mode (context);
    g_assert_cmpint (input_mode, ==, transitions[i].next_input_mode);
  }
}
