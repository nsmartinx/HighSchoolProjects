using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class Trigger : MonoBehaviour
{
    public AudioSource audioSource;
    public AudioClip clip;
    public float volume = 0.5f;
    public float textTime = 1;
    public string textLine;
    public string layerMask;

    public TextMeshProUGUI text;
    bool used = false;
    float timer;
    bool textRemoved = false;

    public GameObject nextTrigger;

    public void TriggerActivate()
    {
        if (!used)
        {
            timer = textTime;
            audioSource.PlayOneShot(clip, volume);
            used = true;
            text.text = textLine;
        }
    }
    public void Update()
    {
        if (timer > 0 && used)
        {
            timer -= Time.deltaTime;
        }
        else if (!textRemoved && used)
        {
            text.text = " ";
            textRemoved = true;
            nextTrigger.layer = LayerMask.NameToLayer(layerMask);
        }
    }
}
