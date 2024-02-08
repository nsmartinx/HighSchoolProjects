using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FadeInTrigger : MonoBehaviour
{
    public SpriteRenderer FadeOut;
    public SpriteRenderer FadeIn;
    bool used = false;
    float timer = 0, time = 2;
    public void TriggerActivate()
    {
        if (!used)
        {
            timer = time;
            used = true;
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (timer > 0 && used)
        {
            timer -= Time.deltaTime;

            Color tmp = FadeOut.color;
            tmp.a = timer / time;
            FadeOut.color = tmp;

            tmp = FadeIn.color;
            tmp.a = 1 - (timer / time);
            FadeIn.color = tmp;
        }
    }
}
