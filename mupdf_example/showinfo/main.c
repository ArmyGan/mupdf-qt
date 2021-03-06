/**
 * @file main.c
 * @brief show infomation of a PDF file(based on mupdf-0.9/apps/win_main.c)
 * @author xiangxw xiangxw5689@126.com
 * @date 2011-12-15
 */

#include <stdlib.h>
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>

int main(int argc, char **argv)
{
    char *filename = (char *)"/home/a/project/mupdf-qt/pdf_files/pdf_reference_1-7.pdf";

	/* open xref */
	fz_context *context = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
    pdf_document *xref = (pdf_document *)fz_open_document(context, filename);
	if (NULL == xref) {
		printf("can't open document: %s\n", filename);
        exit(EXIT_FAILURE);
	}

	/* print infomation */
	pdf_obj *info = pdf_dict_gets(pdf_trailer(xref), "Info");
	if (info) {
		pdf_obj *obj = NULL;
		obj = pdf_dict_gets(info, (char *)"Title"); /* print title */
		if (obj) {
            printf("Title: %s\n", pdf_to_utf8(xref, obj));
		}
		obj = pdf_dict_gets(info, (char *)"Subject"); /* print subject */
		if (obj) {
            printf("Subject: %s\n", pdf_to_utf8(xref, obj));
		}
		obj = pdf_dict_gets(info, (char *)"Author"); /* print author */
		if (obj) {
            printf("Author: %s\n", pdf_to_utf8(xref, obj));
		}
		obj = pdf_dict_gets(info, (char *)"Keywords"); /* print keywords */
		if (obj) {
            printf("Keywords: %s\n", pdf_to_utf8(xref, obj));
		}
		obj = pdf_dict_gets(info, (char *)"Creator"); /* print creator */
		if (obj) {
            printf("Creator: %s\n", pdf_to_utf8(xref, obj));
		}
		obj = pdf_dict_gets(info, (char *)"Producer"); /* print producer */
		if (obj) {
            printf("Producer: %s\n", pdf_to_utf8(xref, obj));
		}
		obj = pdf_dict_gets(info, (char *)"CreationDate"); /* print creation date */
		if (obj) {
            printf("CreationDate: %s\n", pdf_to_utf8(xref, obj));
		}
		obj = pdf_dict_gets(info, (char *)"ModDate"); /* print mod date */
		if (obj) {
            printf("ModDate: %s\n", pdf_to_utf8(xref, obj));
		}
	}

	/* clean */
    fz_close_document((fz_document *)xref);
	fz_free_context(context);
	return 0;
}
