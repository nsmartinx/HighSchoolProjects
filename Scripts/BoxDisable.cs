using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class BoxDisable : MonoBehaviour
{
    public TextMeshProUGUI text;
    public GameObject box;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (text.text == " ")
            box.SetActive(false);
        else
            box.SetActive(true);
    }
}
